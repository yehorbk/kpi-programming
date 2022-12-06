apt update

apt-get install openjdk-11-jre curl vim -y

mkdir -p /opt/sample
chown ${USER}:${GROUP} /opt/sample

curl -sSL https://storage.googleapis.com/devops-practice-files/systemd/ServicesLab-0.0.1.jar --output /opt/sample/service.jar
