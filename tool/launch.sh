#!/bin/bash

if [ z$1 == "zstop" ]; then
	./pro_ctrl.sh -s lobby -c stop
	sleep 5
	./pro_ctrl.sh -s dbagent -c stop
else
	./pro_ctrl.sh -s lobby -c stop
	sleep 5
	./pro_ctrl.sh -s dbagent -c stop
	./pro_ctrl.sh -s dbagent -c start
	./pro_ctrl.sh -s lobby -c start
fi
