TESTS = config_json crawler data_handler manager page page_data_analyzer pages_connectios search term url_data url_data_download query

check:
	$(foreach T, $(TESTS), $(MAKE) -C $(T) check;)

clean:
	$(foreach T, $(TESTS), $(MAKE) -C $(T) clean;)

recheck: clean check
