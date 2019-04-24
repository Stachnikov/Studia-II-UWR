require 'test/unit'

def palindrome?(napis)
  napis.downcase.scan(/\w/) == napis.downcase.scan(/\w/).reverse
end

def count_words(napis)
  hash_table = Hash.new(0)
  napis = napis.downcase.scan(/\w+/)
  for i in (0...napis.length) 
      if(hash_table.include?(napis[i]))
        hash_table[napis[i]] = hash_table[napis[i]] + 1
      else
        hash_table[napis[i]] = 1
      end
    end 
    hash_table
end

def same23?(tab)
  hash_table = Hash.new(0)
  for i in (0...tab.length) 
      if(hash_table.include?(tab[i]))
        hash_table[tab[i]] = hash_table[tab[i]] + 1
      else
        hash_table[tab[i]] = 1
      end
    end 
    return (hash_table.has_value?(2) && hash_table.has_value?(3))
end

class Testing < Test::Unit::TestCase
  def test1
    puts "Palindrom"
    assert_equal(palindrome?("A man, a plan, a canal -- Panama"),true)
    assert_equal(palindrome?("Madam, I'm Adam!"),true)
    assert_equal(palindrome?("Abracadabra"),false)
    assert_equal(palindrome?(""),true)
  end
  def test2
    puts "Count Words"
    assert_equal(count_words("A man, a plan, a canal -- Panama"), {'a' => 3, 'man' => 1, 'canal' => 1, 'panama' => 1, 'plan' => 1})
  end
  def test3
    puts "Same23?"
    assert_equal(same23?(["a", "a", "a", "b", "b"]),true)
    assert_equal(same23?(["a", "b", "c", "b", "c"]),false)
    assert_equal(same23?(["a", "a", "a", "a", "a"]),false)
    assert_equal(same23?(["a", "b", "a", "b", "a"]),true)
  end
end