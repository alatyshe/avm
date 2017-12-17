require_relative "../lib/should_equal.rb"

file = "misc/files/#{File.basename(__FILE__)}"
test = "misc/files/#{File.basename(__FILE__, ".*")}.avm"
output = "misc/output/#{File.basename(__FILE__, ".*")}.txt"
r = system "./avm #{test} > #{output}"
if r
	fd = File.open(output, "rb")
	content = fd.read
	should_equal("Line 4 : [1;31mERROR [0;0m: Pop on Empty stack\n", content, file)
else
	puts "Error returned by avm !".red
end