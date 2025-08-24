#include <string>
#include <iostream>

int main() {
  std::string s1("What is the sound of one clam napping?");
  std::string s2("Anything worth doing is worth overdoing.");
  std::string s3("I saw Elvis in a UFO.");

  // copy the first 8 chars (indices [0..7]) from s1.
  // from libft ft_substr()
  std::string s4(s1, 0, 8);   // "What is "

  // copy 6 chars starting at index 15 from s2.
  std::string s5(s2, 15, 6);  // "doing "

  // copy from the middle (index 6) to the end of s3.
  std::string s6 = s3.substr(6);  // "Elvis in a UFO."

  // Build a combined quote using pieces.
  // Note: added spaces around words so the sentence reads naturally.
  std::string quoteMe =
      s4 + "that" +				//"What is that "
      s1.substr(20, 10) +		// 10 chars from s1 at index 20: "sound of "
      s5 +						// "doing "
      "with" +
      s3.substr(5) +			// from index 5 to end: " Elvis in a UFO."
      s1.substr(37, 1);			// single char at index 37: likely "?"

  std::cout << quoteMe << std::endl;
}
