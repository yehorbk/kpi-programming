#!/bin/bash

Help()
{
   echo "Create Kubernetes secret with DockerHub credentials"
   echo
   echo "Syntax: dockerconfig.sh -u USERNAME -p SECRET"
   echo "options:"
   echo "u     DockerHub username"
   echo "p     DockerHub password or token"
   echo
}

while getopts ":u:p:" option; do
   case $option in
      u)
         DOCKER_USERNAME=$OPTARG;;
      p)
         DOCKER_PASSWORD=$OPTARG;;
     \?)
         echo "Invalid option."
         exit;;
   esac
done

if [[ -z $DOCKER_USERNAME || -z $DOCKER_PASSWORD ]]; then
  Help
  exit
fi

CREDENTIALS=`cat <<EOF | base64 | tr -d '\n\r'
{
  "auths": {
    "https://index.docker.io/v1/": {
      "auth": "$(echo -n ${DOCKER_USERNAME}:${DOCKER_PASSWORD} | base64)"
    }
  }
}
EOF`

cat <<EOF | kubectl apply -f -
apiVersion: v1
kind: Secret
metadata:
  name: credentials
  namespace: jenkins
type: Opaque
data:
  config.json: ${CREDENTIALS}
EOF