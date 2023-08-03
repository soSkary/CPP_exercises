Exercise 1

If you haven't already, create unit tests for your heap array type (ex 8.3.1), enable the sanitizers with the compiler

add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)
In your cmake file should do the trick.  It's useful to have this as an option in cmake, so you can toggle whether or not you want to enable sanitizers without editing the cmake file every time.

 

Example 2

Add unit tests that use the type you created previously, that counts its constructor calls as your element type.  (ex. 8.2.1)

Make sure that calls to the constructors equal the calls to the destructor.

Run the unit tests with sanitizers enabled.  Fix any clear errors.  Pay extra attention when moving the types around.

(It's likely you'll have no problems, but you want to be sure with this one)

 

Example 3

Disable the sanitizers from the build (since they don't always play along with valgrind), and use valgrind to go through the unit tests for ex1.  Make sure valgrind reports that no leaks were possible.

