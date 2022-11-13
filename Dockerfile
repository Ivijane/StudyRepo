FROM gcc:9.5

WORKDIR /app

COPY . .

RUN apt-get update && apt-get install -y cmake libgtest-dev libboost-test-dev && rm -rf /var/lib/apt/lists/*

CMD ["cmake"]