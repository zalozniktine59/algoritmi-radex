#uporabi ubuntu
FROM ubuntu:latest

#uporabi /app kot delovni direktorij v docker zabojniku
WORKDIR /app

#kopira vse datoteke v trenutni mapi v /app v docker zabojniku
COPY . /app

#ko se docker zabojnik zažene, zbuilda program in ga zažene
CMD g++ test.cpp main.cpp -o test_program && ./test_program