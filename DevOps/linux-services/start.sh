podman run \
  -d -p 8888:8888 \
  --volume $(pwd)/volume/sample.service:/etc/systemd/system/sample.service \
  --name linux-services-container \
  linux-services

podman exec \
  -it -u 0 \
  linux-services-container \
  bash
