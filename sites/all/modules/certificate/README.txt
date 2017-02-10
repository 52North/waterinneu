Create and award PDF certificates.

Features

     * Interface for managing custom certificate templates and mappings
     * Built-in CCK Content profile field mapping
     * API for module-provided map options
     * Use of Tokens for certificate display
     * Integration with Wysiwyg for rich certificates
     * Bundled Signup and Quiz integration example
     * Utilizes Print module for PDF output (use any supported PDF
       generator)

Getting started

    1. Install certificate module
    2. Ensure a PDF generator is selected in Configuration -> Printer,
       email and PDF versions.
    3. Edit your content type that will be awarding certificates (e.g.
       Quiz, Course) and make sure "Award certificate" is checked.
    4. Create the Course or any other certificate-ready activity
       (enable bundled certificate_signup or certificate_quiz for awarding
       Certificates on Signup attendance or Quiz completion).
    5. Select the certificate you want to award by setting the mapping
       options on your activity node.

Modules that use certificate

     * Course - awards a certificate on completion of an e-learning
       course with course_certificate

Certificate mapping

     * Certificate has the ability to award different certificates
       depending on arbitrary criteria. You may use the Rules engine
       to build selection logic.
     * You can also use the built in mapper API for more complex mapping.
       See certificate.api.php for documentation.

Dependencies

     * Print

Credits

     * This project is sponsored by DLC Solutions for EthosCE, an
       enterprise-level Learning Management System (LMS).
