What is Yttrium?
====================

Yttrium is intended to be a language and virtual machine 
capable of being used for systems-level programming. To facilitate this, it
will be developed alongside an OS.

The VM will be made to run on both a BeagleBoard-xM and on top of Linux.

The Language
============

The plan is for a functional language that is statically typed. However, the
types will be expressed as plain values in the language. This will require
exposing the runtime to the compiler and the compiler to the runtime much as it
is in a LISP.

Since the compiler will be running on a platform independent of the final
target and behavior of the two must be closely coupled, a bytecode interpreter
was chosen as the target and virtual machines will be made for the various
targets.

In order to bootstrap the compiler, an interpreter will be created to allow a
compiler to be written in Yttrium.

`README.md` in the `compiler` and `interpreter` directories for more
information.

The VM
======

The chosen virtual machine design is a register machine. This was chosen for
simplicity of implementation and to later allow simple creation of a JIT-ed
runtime.

See `README.md` in the `vm` directory.

The Harness
===========

The harness is designed to allow uploading executables to the VM on the
BeagleBoard. It will also be used as both a local and a remote REPL. Ideally 
this will be written in Yttrium with minimal C to manage talking to the
serial port. 

See `README.md` in the `harness` directory.

-----

This is just for fun. Any ideas or suggestions are welcome.
