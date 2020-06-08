# Read YAML file
import struct

import yaml
import matplotlib.pyplot as plt
from matplotlib import patches

lowest = 15 * 16 + 15
middle = lowest << (2 * 4)
highest = middle << (2 * 4)


def to_16bit(c):
    rgb = [(c & highest) >> 16, (c & middle) >> 8, c & lowest]
    r, g, b = [component / 255 for component in rgb]
    rgb = r * 31, g * 63, b * 31
    r, g, b = [int(component) for component in rgb]
    rgb = (r << (5 + 6)) + (g << 5) + b
    return rgb


def int2hex_string(c):
    return "#{0:0{1}x}".format(c, 6)


def to_rgb(c):
    r = (c & 0b11111_000000_00000) >> (5 + 6)
    g = (c & 0b00000_111111_00000) >> 5
    b = c & 0b00000_000000_11111

    return r / 31, g / 63, b / 31


def test(base, transformed):
    fig, ax = plt.subplots(1)
    rect = patches.Rectangle((0, .5), 1, .5, linewidth=1, facecolor=int2hex_string(base))
    ax.add_patch(rect)

    rect = patches.Rectangle((0, 0), 1, .5, linewidth=1, facecolor=to_rgb(transformed))
    ax.add_patch(rect)

    plt.show()


def rect2bytes(rect):
    # left, top, width, height = rect
    return struct.pack('iiii', *rect)


from pathlib import Path

Path("binary").mkdir(parents=True, exist_ok=True)

with open("textures.yaml", 'r') as stream:
    data_loaded = yaml.safe_load(stream)
    colors = {name: to_16bit(color) for name, color in data_loaded['colors'].items()}
    for name, texture in data_loaded['textures'].items():
        b = bytearray()
        num_rectangles = sum(len(rectangles) for rectangles in texture.values())
        b += struct.pack('B', num_rectangles)

        for color, rectangles in texture.items():
            for rect in rectangles:
                b += struct.pack('H', colors[color])
                b += rect2bytes(rect)

        with open(f"binary/{name}.texture", "wb") as f:
            f.write(b)
