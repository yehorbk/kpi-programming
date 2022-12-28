# Simple Docker, Kubernetes & Jenkins task

## Before tasks

### If you have GitLab account
Fork this project by clicking [https://gitlab.com/DmyMi/k8s-simple-task/-/forks/new](https://gitlab.com/DmyMi/k8s-simple-task/-/forks/new)
### If you have GitHub account
Follow this article [https://nira.com/how-to-migrate-from-gitlab-to-github/](https://nira.com/how-to-migrate-from-gitlab-to-github/) to copy the project to your Github.

Doing the lab requires you to know how to use Git :)

## Prereq
### Ubuntu
1. Install Docker by following this link: [Docker Install](https://docs.docker.com/engine/install/ubuntu/)
2. [Install MicroK8S](https://microk8s.io/docs/getting-started)
3. Enable MicroK8s addons:
```bash
# You need to provide a valid IP range in your local network.
# Can be as few as 1, but better to have some to spare
# Following IP range is for an example.
microk8s enable dns registry metallb:192.168.0.10-192.168.0.20
```
4. Configure insecure registry access for Docker [as described in this dockumentation](https://microk8s.io/docs/registry-built-in)

### Centos
1. Install Docker by following this link: [Docker Install](https://docs.docker.com/engine/install/centos/)
2. Install K3S
```bash
curl -sfL https://get.k3s.io | sh -s - --write-kubeconfig-mode 644
```

### MacOS
1. You should already have Docker for Mac
2. [Install kubectl](https://kubernetes.io/docs/tasks/tools/install-kubectl-macos/)

### Windows
1. You should already have Docker for Windows
2. [Install kubectl](https://kubernetes.io/docs/tasks/tools/install-kubectl-windows/)

## Workflow
1. Clone the repository
```bash
git clone https://gitlab.com/DmyMi/k8s-simple-task.git
```
2. Change to directory
```bash
cd k8s-simple-task
```

3. Apply already provided manifests
```bash
# Ubuntu
microk8s kubectl apply -f ./k8s
# Centos
k3s kubectl apply -f ./k8s
# Mac & Windows
kubectl apply -f ./k8s
```

4. Wait up to 5 minutes (depending on your internet and pc it might take some time to start) and check if everything is working.
In the terminal write:
```bash
# I will simply write kubectl, you need a prefix for your environment
kubectl port-forward svc/backend 8080:8080
```
Leave this terminal working, and OPEN A NEW TERMINAL (or use your browser).
In new terminal run:
```bash
curl http://localhost:8080/api/books
```
If everything is fine yo should see a list of books.

## Task 1: Docker & K8s
### Dockerfile
First, write a Docker file for `express-fe` application.

Create account on [Docker Hub](https://hub.docker.com/). Go to [Security](https://hub.docker.com/settings/security) and create a new access token.
Follow the instructions to login your Docker to Docker Hub.

> Note: Make sure you save the token if you will do the Jenkins part

Tag the image with your docker hub repository, e.g. `dmytro/express-fe`. [Example](https://nodejs.org/en/docs/guides/nodejs-docker-webapp/)

### K8s manifests
Write a `frontend-deployment.yaml`. Remember that `express-fe` needs some environment variables set. Check its readme. [Example](https://kubernetes.io/docs/concepts/workloads/controllers/deployment/)

Write a `frontend-service.yaml`. For Ubuntu it can be `LoadBalancer`, for others - `NodePort`. [Example](https://kubernetes.io/docs/concepts/services-networking/service/)

Apply these manifests and try to check if the Express works.
```bash
kubectl apply -f ./k8s
# Get the services
kubectl get svc
```
For Ubuntu check loadbalancer ip and visit it, for example: `192.168.0.10:3000/api-docs`

For other OS, check node port and visit it, for example: `localhost:32758/api-docs`

## Task 2: Jenkins
You need to have a local K8s Cluster created (using Docker for Desktop, Microk8s, k3s, etc.). You need to have `kubectl` installed (not covered here).

```bash
cd jenkins
./deploy.sh
# Wait 5 minutes
export SERVICE_IP=$(kubectl get svc --namespace jenkins jenkins --template "{{ range (index .status.loadBalancer.ingress 0) }}{{ . }}{{ end }}")
echo http://$SERVICE_IP:80/login
```

Running previous commands ill create a playground with Jenkins Controller configured using Jenkins Configuration as Code with access to K8S cluster.
Login: `admin`
Password: `verysecret`

### DockerHub credentials
After creating Jenkins deployment - create DockerHub credentials secret using the `dockerconfig.sh` script.
```bash
./dockerconfig.sh -u "vasya" -p "your-dockerhub-token-or-password"
```

### Task

Write missing pieces of Jenkinsfile. Mainly:
* "testing" the application
* Deploying the application
* Testing the deployment using curl :)

## Cleanup

```bash
kubectl delete -f ./k8s
kubectl delete ns jenkins
```

## Submission

All i need is a link to your Github/Gitlab project in Classroom.
