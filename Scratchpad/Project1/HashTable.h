#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <algorithm>
#include <vector>
#include <stdexcept>

template<typename Key, typename Value> 
class HashTable {
public:
	using key_type = Key;
	using mapped_type = Value;
	using size_type = std::size_t;

	struct HashEntry {
		explicit HashEntry(key_type k, mapped_type v) : key(k), value(v) {}
		~HashEntry() = default;
		key_type key; 
		mapped_type value;
		HashEntry(const HashEntry& entry) = default;
		HashEntry& operator=(const HashEntry& entry) = default;
	};

	HashTable(size_type size = 101) : table(size) {};
	mapped_type& at(const key_type& key);
	void insert(const HashEntry& val);
	void erase(const key_type& key);
	void clear();
	mapped_type& operator[](const key_type& key);
	
	bool empty();
	size_type size();


private:
	std::vector<std::vector<HashEntry>> table;
	size_type hash_function(const key_type&) const;
	void rehash();
	size_type numEntries;
};


template<typename Key, typename Value>
Value& HashTable<Key, Value>::at(const key_type& key) {
	size_type index = hash_function(key);
	auto& bucket = table[index];
	auto itr = std::find_if(begin(bucket), end(bucket), [&key](const HashEntry& entry) { return entry.key == key; });
	if (itr != end(bucket)) {
		return itr->value;
	}
	else {
		throw std::out_of_range("Key not in table");
	}
}

template<typename Key, typename Value>
Value& HashTable<Key, Value>::operator[](const key_type& key) {
	return at(key);
}

template<typename Key, typename Value>
void HashTable<Key, Value>::insert(const HashEntry& val) {
	size_type index = hash_function(val.key);
	auto& bucket = table[index];
	auto itr = std::find_if(begin(bucket), end(bucket), [&val](const HashEntry& entry) {return entry.key == val.key; });
	if (itr == end(bucket)) {
		bucket.push_back(val);
		numEntries++;
	}

	float load_factor = 1.0f * numEntries / table.size();
	if (load_factor > 0.5f) {
		rehash();
	}

}

template<typename Key, typename Value>
void HashTable<Key, Value>::erase(const key_type& key) {
	size_type index = hash_function(key);
	auto& bucket = table[index];
	auto itr = std::find_if(begin(bucket), end(bucket), [&key](const HashEntry& entry) {return entry.key == key; });
	if (itr != end(bucket)) {
		bucket.erase(itr);
		numEntries--;
	}
}

template<typename Key, typename Value>
void HashTable<Key, Value>::clear() {
	table.clear();
	numEntries = 0;
}

template<typename Key, typename Value>
bool HashTable<Key, Value>::empty() {
	return numEntries == 0;
}

template<typename Key, typename Value>
std::size_t HashTable<Key, Value>::size() {
	return numEntries;
}

template<typename Key, typename Value>
std::size_t HashTable<Key, Value>::hash_function(const key_type&) const {
	// hashVal %= table.size();
	// return hashVal
	return 0;
}

template<typename Key, typename Value>
void HashTable<Key, Value>::rehash() {
	std::vector<std::vector<HashEntry>> temp = table;
	table.clear();
	table.resize(2 * table.size());
	for (auto buckets : temp) {
		for (auto entry : buckets) {
			insert(entry);
		}
	}



}

#endif