package main

import (
	"fmt"

	do "gopkg.in/godo.v2"
)

func tasks(p *do.Project) {
	p.Task("counter", nil, func(c *do.Context) {
		name := "counter"
		c.Bash(fmt.Sprintf("gcc %s/*.c -o %s.o -l pthread", name, name))
		c.Bash(fmt.Sprintf("./%s.o", name))
	}).Src("counter/**/*.{c,h}")

	p.Task("mutex_counter", nil, func(c *do.Context) {
		name := "mutex_counter"
		c.Bash(fmt.Sprintf("gcc %s/*.c -o %s.o -l pthread", name, name))
		c.Bash(fmt.Sprintf("./%s.o", name))
	}).Src("mutex_counter/**/*.{c,h}")

	p.Task("semaphore_helloworld", nil, func(c *do.Context) {
		name := "semaphore_helloworld"
		c.Bash(fmt.Sprintf("gcc %s/*.c -o %s.o -l pthread", name, name))
		c.Bash(fmt.Sprintf("./%s.o", name))
	}).Src("semaphore_helloworld/**/*.{c,h}")
}

func main() {
	do.Godo(tasks)
}
