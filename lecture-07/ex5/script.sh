#!/bin/bash
echo "sudo groupadd labgrp"
echo "sudo useradd labusr -d /bin/bash"
echo "sudo usermod -aG sudo labusr"
echo "sudo passwd root"