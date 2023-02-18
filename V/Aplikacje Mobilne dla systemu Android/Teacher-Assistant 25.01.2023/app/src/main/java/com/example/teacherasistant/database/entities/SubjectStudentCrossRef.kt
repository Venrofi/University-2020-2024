package com.example.teacherasistant.database.entities

import androidx.room.Entity

@Entity(primaryKeys = ["subjectId", "studentId"], tableName = "subject_student_table")
data class SubjectStudentCrossRef(
    val subjectId: Long,
    val studentId: Long
)
