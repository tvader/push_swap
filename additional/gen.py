#!/usr/local/bin/python3
import random, argparse

parser = argparse.ArgumentParser(description='Randomize array of int')
parser.add_argument('array_len', metavar='n', type=int, help='size of the array')

args = parser.parse_args()
list = [i for i in range(-args.array_len // 2, args.array_len // 2)];
random.shuffle(list)
for i in list:
	print (i, end=' ')

