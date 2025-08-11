# make test LANG=python NAME=top_k
# make run LANG=cpp NAME=top_k

.PHONY: test run

test:
ifeq ($(LANG),python)
	@cd python/$(NAME) && pytest -q
else ifeq ($(LANG),cpp)
	@cd cpp/$(NAME) && g++ -std=c++20 -O2 $(NAME).cpp -o $(NAME) && ./$(NAME)
else ifeq ($(LANG),rust)
	@cd rust/$(NAME) && cargo test
else ifeq ($(LANG),c)
	@cd c/$(NAME) && gcc -std=c11 -O2 $(NAME).c -o $(NAME) && ./$(NAME)
else
	@echo "❌ Especifica LANG=python|cpp|rust|c y NAME=<ejercicio>"; exit 1
endif

run:
ifeq ($(LANG),python)
	@cd python/$(NAME) && python3 $(NAME).py
else ifeq ($(LANG),cpp)
	@cd cpp/$(NAME) && g++ -std=c++20 -O2 $(NAME).cpp -o $(NAME) && ./$(NAME)
else ifeq ($(LANG),rust)
	@cd rust/$(NAME) && cargo run
else ifeq ($(LANG),c)
	@cd c/$(NAME) && gcc -std=c11 -O2 $(NAME).c -o $(NAME) && ./$(NAME)
else
	@echo "❌ Especifica LANG=python|cpp|rust|c y NAME=<ejercicio>"; exit 1
endif
