#ifndef ARCUS_DIALOG_H
#define ARCUS_DIALOG_H

namespace arcus {
	class Dialog {
	public:

		Dialog(const std::string, const std::vector<std::string>);

		void chooseAnswer(int);
		std::string present() const;

	private:
		const std::string statement;
		const std::vector<std::string> answers;
		int latestAnswer;
	};

}

#endif