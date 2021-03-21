## Server

### Compile

```shell
gcc -o server server.c
```

### Run

```shell
./server  
```



## Client

### Complie 

```shell
gcc -o client client.c    
```

### Run

```shell
./client 127.0.0.1 8080 [Client_Name]
```

- The server can receive information from multiple clients at the same time, and use different client names to classify the clients.

