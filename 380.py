import random


class RandomizedSet:

	def __init__(self):
		"""
		Initialize your data structure here.
		"""
		self.data = {}
		self.keys = []

	def insert(self, val):
		"""
		Inserts a value to the set. Returns true if the set did not already contain the specified element.
		:type val: int
		:rtype: bool
		"""
		if val in self.data:
			return False
		else:
			self.data[val] = len(self.keys)
			self.keys.append(val)
			return True

	def remove(self, val):
		"""
		Removes a value from the set. Returns true if the set contained the specified element.
		:type val: int
		:rtype: bool
		"""
		if val in self.data:
			last = self.keys[-1]

			idx = self.data[val]

			self.keys[idx] = last
			del self.keys[-1]

			self.data[last] = idx
			del self.data[val]

			return True
		else:
			return False

	def getRandom(self):
		"""
		Get a random element from the set.
		:rtype: int
		"""
		if self.keys:
			return random.choice(self.keys)
