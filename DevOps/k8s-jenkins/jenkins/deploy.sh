#!/bin/bash
kubectl create ns jenkins
kubectl apply -f ./manifests
kubectl create configmap jenkins-config --from-file=./config/jenkins.yaml --from-file=./config/plugins.txt --namespace jenkins