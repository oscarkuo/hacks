require './PassBlock'
obj = PassBlock.new
puts obj.find {|i| i == 'row1'}

enu = obj.find

enu.each do |n|
  puts n
end


