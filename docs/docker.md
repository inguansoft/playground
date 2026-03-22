






docker image pull ubuntu:latest

docker container run --rm -it ubuntu:22.04 /bin/bash
docker container run --rm -d -t ubuntu /bin/bash
3c4f916619a5dfc420396d823b42e8bd30a2f94ab5b0f42f052357a68a67309b
docker container exec -it 9f09ac4bcaa0 /bin/bash
-d run a daemon
docker container logs <nginx-test>

docker container stop 3c4f916619a5.

docker container inspect 3c4f916619a5

docker volume create my-data
docker volume inspect my-data
Now you can start a container with this data volume attached to it by running the following:

 $ docker container run --rm \
     --mount source=my-data,target=/app \
     ubuntu:latest touch /app/my-persistent-data

docker volume rm my-data

docker container ls
docker ps -a
docker container ls --all

docker container stats
docker container stats stress

First, start up a container that you can read statistics from:

$ docker container run --rm -d --name stress \
    docker.io/spkane/train-os:latest \
    stress -v --cpu 2 --io 1 --vm 2 --vm-bytes 128M --timeout 60s
curl --no-buffer -XGET --unix-socket /var/run/docker.sock http://docker/containers/stress/stats
curl -s -XGET --unix-socket /var/run/docker.sock http://docker/containers/stress/stats | head -n 1 | jq

docker volume ls



This command is intended to be run directly on a Linux Docker server. It will not work properly when run from a Windows or macOS system.
$ docker container run \
  --volume=/:/rootfs:ro \
  --volume=/var/run:/var/run:ro \
  --volume=/sys:/sys:ro \
  --volume=/var/lib/docker/:/var/lib/docker:ro \
  --volume=/dev/disk/:/dev/disk:ro \
  --publish=8080:8080 \
  --detach=true \
  --name=cadvisor \
  --privileged \
  --rm \
  --device=/dev/kmsg \
  gcr.io/cadvisor/cadvisor:latest
  http://172.17.42.10:8080/) and the various detailed charts it has for the host and individual containers

  docker build -t coe00 .
  docker run coe00

docker context list
docker context create vagrant --docker host=tcp://127.0.0.1:12375 vagrant
docker context use vagrant