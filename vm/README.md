General
=======

The VM will be a register- as opposed to a stack-based VM. This was a design 
choice to better align the structure of the virtual machine with that of real
world machines and to make it easier to make an efficient runtime and later a 
JIT-ed runtime.

The VM has 256 registers which are tied to the current stack-frame (this is
inspired by the Lua virtual machine). To pass arguments to a subroutine, a new
stack-frame is created which overlaps the previous one and shares the relevant
registers.

Memory allocation is performed at two levels: a coarse level that is intended
to be used at most once per subroutine, and a fine level that can occur many
times within a subroutine. The coarse level will allow both allocating and
deallocating but the fine level will not. In the language, the coarse level
will be represented as regions that can be passed into functions to allow the 
escaping of variables. 

Each opcode will be composed of one 6-bit field to specify what operation to
perform, one 8-bit field to specify (in general) the destination register, and
two 9-bit fields to specify (in general) the operand registers. The 9-bit
operands allows for selection from the general purpose registers or a special
constant register that is included along with the executable.

Portable VM
===========

The first virtual machine to be implemented (after the interpreter, if that
counts) is a portable interpreter written in C intended to compile and run on
Linux. It may or may not compile on other Unix-y systems and might work on
Windows with Cygwin.

The design of this runtime will be focused on clearly documenting the intended
behavior of a Beagle Lang VM and will only care about performance as long as it
doesn't impede clarity.

Beagle VM
=========

This is the VM designed to run on bare metal on a BeagleBoard-xM. This will be
written mostly (or wholly) in ARM assembly and will be built for speed! 
