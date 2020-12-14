require 'RMagick'

list = %w[Manuel Adriana Mary Mama Mauricio]

size = list.count
left_members = list.dup

list.each do |member|

  target = member
  index = 0
  while target == member
    index = rand left_members.count
    target = left_members[index]
    #print " #{index} #{member} -> #{target}\n"
  end
  left_members.delete_at index

  canvas = Magick::Image.new(300, 100) { self.background_color = 'white' }
  gc = Magick::Draw.new
  gc.pointsize(50)
  gc.text(30, 70, "#{target}".center(14))

  gc.draw(canvas)
  canvas.write("#{member}.png")
end