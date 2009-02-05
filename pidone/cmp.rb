#!/usr/bin/env ruby
count=0
rpi=File.open "realpi.txt"
line=rpi.readline
out=File.open "out.txt"
line2=out.readline
puts line
puts line2
minl=line.length
minl=line2.length if line.length>line2.length
while count<minl && line[count]==line2[count]
    count = count + 1
end
puts count.to_s+"\t"+minl.to_s
