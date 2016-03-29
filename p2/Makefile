top:
	javac -d classfiles -sourcepath src src/Trees.java
test:
	@echo testing simple BST
	java -classpath classfiles Trees -1 mytestcorpus mytestcommands
	@echo testing red-black tree
	java -classpath classfiles Trees -2 mytestcorpus mytestcommands
clean:
	rm -f classfiles/*.class
