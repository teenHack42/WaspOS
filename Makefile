#!/bin/bash

all:
	@make -C src
	@make -f Makefile-ISO
