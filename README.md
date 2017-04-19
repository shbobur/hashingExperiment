# hashingExperiment

This is simple QTcpServer using QThreadPool. In experiment we evaluated computaion&memory usage (or requirement) of different hashing functions.

It receives "authentication" requests from client and hashes (with given hash function) password with salt given number of times. It doesn't have database so simply hashes random password with random salt.

Now it supports argon2, bcrypt, scrypt and sha512 hashing functions.

