General
=======

Yttrium will be self-hosting. Since the language will also be used to fully
express its type system, the compiler will need to access the runtime and the 
runtime needs to be able to access the compiler.

The Language
============

My conception for the language is inspired partially by the want to use
high-level languages like Haskell on bare hardware and also by cool languages
such as Lux (unaffiliated) and ATS. The syntax will likely by a lot like that 
of the ML family of languages.

One idea for the language is using the type system, which is just as powerful
as the language itself, to guarantee that memory is treated properly. The idea
is that memory can be allocated in a "region" that can all be deallocated at
once. It can be checked that memory isn't used after the region it is allocated
in is deallocated. Regions will be tied to a particular stack-frame and will be
freely expandable.

Bootstrapping
=============

Since the compiler requires a working runtime, the language will be created in
an interpreter first that will be used to compile the first versions of the
compiler until it is self-hosting.
