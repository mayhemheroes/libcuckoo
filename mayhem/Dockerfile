FROM --platform=linux/amd64 ubuntu:22.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential clang
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y cmake

COPY . /repo

RUN clang++ /repo/mayhem/fuzz_find.cpp -fsanitize=fuzzer,address -I /repo/ -o /fuzz

FROM ubuntu:22.04 as package

COPY --from=builder /fuzz /fuzz_find
