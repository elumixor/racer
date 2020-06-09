import struct

from PIL import Image

img = Image.open("myfont.bmp")
pixels = img.load()

size = 8
num_glyphs = 39

RED_PIXEL = (255, 0, 0, 255)
BLACK_PIXEL = (0, 0, 0, 255)

b = bytearray()

for i in range(num_glyphs):
    color1 = []
    color2 = []

    for x in range(i * size, (i + 1) * size):
        for y in range(size):
            if pixels[x, y] == BLACK_PIXEL:
                color1.append((x - i * size, y))
            elif pixels[x, y] == RED_PIXEL:
                color2.append((x - i * size, y))

    b += struct.pack('i', len(color1))
    for x, y in color1:
        b += struct.pack('ii', x, y)

    b += struct.pack('i', len(color2))
    for x, y in color2:
        b += struct.pack('ii', x, y)

with open(f"binary", "wb") as f:
    f.write(b)
