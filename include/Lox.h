#include <string>

class lox
{
  public:
      /// @brief Indicates if an error has occurred during execution.
      static inline bool hadError{false};
      /**
       * @brief Executes the given code string.
       * @param code The source code to execute.
       */
      void run(std::string code);
      /**
       * @brief Executes a Lox script from a file.
       * @param fileName The name of the file containing the Lox script.
       */
      void runFile(std::string fileName);
      /**
       * @brief Starts an interactive prompt for executing Lox code line by line.
       */
      void runPrompt();
      /**
       * @brief Reports an error that occurred at a specific line.
       * @param line The line number where the error occurred.
       * @param message The error message to report.
       */
      static void error(long unsigned int line, std::string message);
      /**
       * @brief Reports an error with additional context information.
       * @param line The line number where the error occurred.
       * @param where Additional context about where the error occurred.
       * @param message The error message to report.
       */

  private:
      static void report(long unsigned int line, std::string where, std::string message);

};
