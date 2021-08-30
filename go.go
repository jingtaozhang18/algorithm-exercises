//proxy.go
package main

import (
	"flag"
	"fmt"
	"io"
	"log"
	"net"
)

var (
	host          string
	port          string
	container     string
	containerport string
)

func main() {
	flag.StringVar(&host, "host", "0.0.0.0", "host addr")
	flag.StringVar(&port, "port", "", "host port")
	flag.StringVar(&container, "container", "", "container addr")
	flag.StringVar(&containerport, "containerport", "8080", "container port")

	flag.Parse()

	fmt.Printf("%s\n%s\n%s\n%s", host, port, container, containerport)

	ln, err := net.Listen("tcp", host+":"+port)
	if err != nil {
		// handle error
		log.Println("listen error:", err)
		return
	}
	log.Println("listen ok")

	for {
		conn, err := ln.Accept()
		if err != nil {
			// handle error
			log.Println("accept error:", err)
			continue
		}
		log.Println("accept conn", conn)
		go handleConnection(conn)
	}
}

func handleConnection(conn net.Conn) {
	cli, err := net.Dial("tcp", container+":"+containerport)
	if err != nil {
		log.Println("dial error:", err)
		return
	}
	log.Println("dial ", container+":"+containerport, " ok")

	go io.Copy(conn, cli)
	_, err = io.Copy(cli, conn)
	if err != nil {
		fmt.Println("communication over: error:", err)
	}

}
