package com.example.teacherasistant.database

import androidx.room.Embedded
import androidx.room.Relation
import com.example.teacherasistant.database.entities.Mark
import com.example.teacherasistant.database.entities.Student

data class StudentWithMarks(
    @Embedded val student: Student,
    @Relation(
        parentColumn = "id",
        entityColumn = "id"
    )
    val marks: List<Mark>
)
