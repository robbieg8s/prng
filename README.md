This is a test harness for experimenting with xoshiro256**

See [https://prng.di.unimi.it].

The content of `xoshiro256starstar.c` was populated by fetching the content
linked there using `curl`:

    :; curl --silent --write-out '%header{Date}\n%header{Last-Modified}\n%header{ETag}\n' --remote-name https://prng.di.unimi.it/xoshiro256starstar.c
    Mon, 22 Jul 2024 01:20:22 GMT
    Tue, 04 Jun 2024 11:45:55 GMT
    "c24-61a0efe1d5425"

Since the state `s` in `xoshiro256starstar.c` must be initialized, and is
`static`, the driver `main.c` directly includes this provided source to avoid
editing it. The driver provides primitive seeding and execution facilities which
were sufficient for my exploratory needs.
