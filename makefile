output: network.o social_network.o user.o post.o
	g++ -std=c++20 $^ -o output

%.o: %.cpp
	g++ -std=c++20 -c $< -o $@

clean:
	rm *.o output
	