#!groovy

pipeline {

    agent {
        kubernetes {
            yaml """
apiVersion: v1
kind: Pod
metadata:
  name: image-builder
  labels:
    robot: builder
spec:
  serviceAccount: jenkins-agent
  containers:
  - name: jnlp
  - name: kaniko
    image: gcr.io/kaniko-project/executor:v1.9.1-debug
    imagePullPolicy: Always
    command:
    - /busybox/cat
    tty: true
    volumeMounts:
      - name: docker-config
        mountPath: /kaniko/.docker/
        readOnly: true
  - name: kubectl
    image: bitnami/kubectl
    tty: true
    command:
    - cat
    securityContext:
      runAsUser: 1000
  - name: node
    image: node:16-alpine
    tty: true
    command:
    - cat
  volumes:
    - name: docker-config
      secret:
        secretName: credentials
        optional: false
"""
        }
    }

    parameters {
        string(name: 'IMAGE_NAME', defaultValue: '', description: 'Your image name in format USER_NAME/IMAGE. You can write it as default value if you want')
    }

    stages {
        stage('Test') {
            steps {
                // TODO: Run 'npm test' using the node container
                // TODO: Make sure you do it inside express-fe folder.
                // Search google for Jenkins pipeline 'dir' function
            }
        }
        stage('Build image') {
            // No need to change, it will work if your Dockerfile is good.
            environment {
                PATH = "/busybox:/kaniko:$PATH"
                HUB_IMAGE = "${params.IMAGE_NAME}"
            }
            steps {
                container(name: 'kaniko', shell: '/busybox/sh') {
                    sh '''#!/busybox/sh
                    /kaniko/executor --dockerfile="$(pwd)/express-fe/Dockerfile" --context="dir:///$(pwd)/express-fe/" --destination ${HUB_IMAGE}:${BUILD_NUMBER}
                    '''
                }
            }
        }
        stage('Deploy') {
            steps {
                // TODO: Need to do two things
                // TODO: First: somehow using bash, substitute new params.IMAGE_NAME and BUILD_NUMBER variable into your frontend deployment.
                // TODO: Hint: bitnami/kubectl has 'sed' utility available
                // TODO: But you can use any other solution (Kustomize, etc.)
                // TODO: Second - use kubectl apply from kubectl container
            }
        }
        stage('Test deployment') {
            agent {
                kubernetes {
                    yaml """
apiVersion: v1
kind: Pod
metadata:
  name: tester
  labels:
    robot: tester
spec:
  serviceAccount: jenkins-agent
  containers:
  - name: jnlp
  - name: ubuntu
    image: ubuntu:22.04
    tty: true
    command:
    - cat
"""
                }
            }
            steps {
                // TODO: Using ubuntu container install `curl`
                // TODO: Use curl to make a request to curl http://frontend:80/books
                // TODO: You probably have to wait for like 60-120 second till everything is deployed for the first time
            }
        }
    }
}
