source_name = hello.c
object_name = hello.o
executable_name = hello

direct: $(souce_name)
	@gcc -o $(executable_name) $(source_name)

through_object_file: $(source_name)
	@gcc -o $(object_name) -c $(source_name)
	@gcc -o $(executable_name) $(object_name)

run: $(source_name) direct
	@./$(executable_name)

clean:
	@rm -f $(object_name) $(executable_name)
