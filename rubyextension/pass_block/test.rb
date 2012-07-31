require './PassBlock'
obj = PassBlock.new

puts 'find by block'
puts obj.find {|i| i == 'row1'}
puts 'done find by block'

puts ''

puts 'return enumerator'
enu = obj.find
puts enu.next
puts 'next 1'
puts enu.next
puts 'next 2'
puts enu.next
puts 'next 3'
puts 'done return enumerator'
