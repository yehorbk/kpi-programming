podman machine init \
  --cpus=2 \
  --disk-size=10 \
  --memory=1024 \
  devops-virtual-machine

podman machine start devops-virtual-machine
