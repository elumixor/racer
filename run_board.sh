ips=(
    192.168.202.203
    192.168.202.212
    192.168.202.207
    192.168.202.127
    192.168.202.211
    192.168.202.204
    192.168.202.213
    192.168.202.209
)

if [ $# -eq 0 ]
then
    echo "Please specify required board. Use indexing from the left: [0, 6]"
else
    if [ $1 -gt 6 ] || [ $1 -lt 0 ]
    then
        echo "Invalid index. Should be in range [0, 6]"
    else
        ip=${ips[$1]}

        echo "Connecting to the board $1 on ip $ip"

        # see https://stackoverflow.com/a/626574/4932128 for the 'bash' part
        ssh -i /opt/zynq/ssh-connect/mzapo-root-key -t root@"$ip" "cd /tmp/yazykvla && ./racer; bash"
    fi
fi
