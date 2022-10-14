ARG BASE=cgr.dev/chainguard/static

FROM --platform=amd64 cgr.dev/chainguard/gcc-glibc@sha256:c94ca43fc6443aaf5b62421ef0e8e49744aecbb6820b1485f387c3925f5bb40d as build

COPY hello.c /hello.c
RUN cc -static /hello.c -o /hello

FROM $BASE

COPY --from=build /hello /hello
CMD ["/hello"]
