# Audio-Recording-Processing-Program
manage and process audio recording files, providing users with detailed information and cost analysis for streaming audio files.
(project)

Key Features:

  User Interface:

    Designed an intuitive command-line interface with a welcome message and main menu options.
    Enabled users to choose between processing a single recording file or multiple recording files, and to quit the program.
    File Type and Quality Selection:

Implemented input validation to ensure correct file type selection:
  MPEG Layer 3 (MP3)
  Waveform Audio File Format (WAV)
Provided options for file quality and format:
  MP3: Standard (160kbps), Premium (192kbps), Ultra (320kbps)
  WAV: Standard (16-bit), High (24-bit), Studio (32-bit)

Audio File Processing:
  Processed and displayed detailed information for each file, including:
  File type and quality/format
  Duration (minutes and seconds)
  File size (MB)
  Cost calculations:
    Subtotal
    Cost per minute and per MB
    Streaming tax
    Total cost

Multiple File Processing:

  Allowed processing of multiple files with cumulative totals:
    Number of recordings streamed
    Total MB streamed
    Total duration
    Total cost
Error Handling:
  Implemented robust input validation to ensure accurate data entry and user-friendly error messages.
  Technologies Used:

C++ programming language
Standard I/O and string handling
Precision formatting for detailed output

Achievements:
  -Developed a comprehensive solution for managing and processing audio recording files.
  -Enhanced user experience with clear prompts and detailed output.
  -Applied advanced C++ concepts such as input validation, string manipulation, and cost calculations.
