FROM gcc:latest

WORKDIR /app

COPY . /app

RUN apt-get update && apt-get install -y \
    build-essential \
    libreadline-dev

RUN make

CMD ["./42sh"]