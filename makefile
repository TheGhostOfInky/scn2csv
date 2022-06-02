target = scn2csv.cpp
base = $(basename $(target))

msvc:
	@cl ./src/$(target) /EHsc /std:c++17 /Fe:.\bin\$(base).exe /Fo:.\bin\$(base).obj /O2

clang-win:
	@clang++ ./src/$(target) -O3 -std=c++17 -o ./bin/$(base).exe

gcc:
	@g++ ./src/$(target) -O3 -std=c++17 -o ./bin/$(base)

clang:
	@clang++ ./src/$(target) -O3 -std=c++17 -o ./bin/$(base)

run:
	@./bin/$(base) .

createbin:
	@mkdir bin

clearbin:
	@rm ./bin/*
