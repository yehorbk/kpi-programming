podman container stop $(podman container ps -q)

podman system prune -a --volumes --force

podman machine stop devops-virtual-machine

podman machine rm -f devops-virtual-machine 
