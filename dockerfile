# Uporabi Ubuntu kot osnovno sliko
FROM ubuntu:latest

# Nastavi delovno mapo v Docker zabojniku
WORKDIR /app

# Kopiraj vse datoteke iz trenutnega direktorija v Docker zabojnik v /app
COPY . /app

# Posodobi seznam paketov in namesti potrebne odvisnosti
RUN apt-get update && \
    apt-get install -y g++ && \
    rm -rf /var/lib/apt/lists/*

# Ko Docker zabojnik zažene, skompiliraj in zaženi testni program
CMD g++ test.cpp main.cpp -o test_program && ./test_program