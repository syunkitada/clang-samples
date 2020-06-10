package main

import (
	"fmt"

	do "gopkg.in/godo.v2"
)

func tasks(p *do.Project) {
	p.Task("helloworld", nil, func(c *do.Context) {
		name := "helloworld"
		c.Bash(fmt.Sprintf("gcc %s/*.c -o %s.o", name, name))
		c.Bash(fmt.Sprintf("./%s.o", name))
	}).Src("helloworld/**/*.{c,h}")

	p.Task("variables", nil, func(c *do.Context) {
		name := "variables"
		c.Bash(fmt.Sprintf("gcc %s/*.c -o %s.o", name, name))
		c.Bash(fmt.Sprintf("./%s.o", name))
	}).Src("variables/**/*.{c,h}")

	p.Task("bit", nil, func(c *do.Context) {
		name := "bit"
		c.Bash(fmt.Sprintf("gcc %s/*.c -o %s.o", name, name))
		c.Bash(fmt.Sprintf("./%s.o", name))
	}).Src("bit/**/*.{c,h}")

	p.Task("flowcontrol", nil, func(c *do.Context) {
		name := "flowcontrol"
		c.Bash(fmt.Sprintf("gcc %s/*.c -o %s.o", name, name))
		c.Bash(fmt.Sprintf("./%s.o", name))
	}).Src("flowcontrol/**/*.{c,h}")

	p.Task("function", nil, func(c *do.Context) {
		name := "function"
		c.Bash(fmt.Sprintf("gcc %s/*.c -o %s.o", name, name))
		c.Bash(fmt.Sprintf("./%s.o", name))
	}).Src("function/**/*.{c,h}")

	p.Task("pointer", nil, func(c *do.Context) {
		name := "pointer"
		c.Bash(fmt.Sprintf("gcc %s/*.c -o %s.o", name, name))
		c.Bash(fmt.Sprintf("./%s.o", name))
	}).Src("pointer/**/*.{c,h}")

	p.Task("struct", nil, func(c *do.Context) {
		name := "struct"
		c.Bash(fmt.Sprintf("gcc %s/*.c -o %s.o", name, name))
		c.Bash(fmt.Sprintf("./%s.o", name))
	}).Src("struct/**/*.{c,h}")

	p.Task("type", nil, func(c *do.Context) {
		name := "type"
		c.Bash(fmt.Sprintf("gcc %s/*.c -o %s.o", name, name))
		c.Bash(fmt.Sprintf("./%s.o", name))
	}).Src("type/**/*.{c,h}")
}

func main() {
	do.Godo(tasks)
}
