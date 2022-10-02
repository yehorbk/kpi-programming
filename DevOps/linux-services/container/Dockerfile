FROM ubuntu:latest

ADD . .

RUN ./install.sh
RUN ./set-up.sh

EXPOSE 8888

CMD ["/sbin/init"]
