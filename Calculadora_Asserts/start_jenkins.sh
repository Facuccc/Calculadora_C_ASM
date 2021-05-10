#!/bin/bash

sudo docker run --rm -u root -p 6666:8080 -v jenkins-data:/var/jenkins_home -v $(which docker):/usr/bin/docker -v /var/run/docker.sock:/var/run/docker.sock -v "$HOME":/home --name Perez-Carrizo_Jenkins jenkins/jenkins:lts



