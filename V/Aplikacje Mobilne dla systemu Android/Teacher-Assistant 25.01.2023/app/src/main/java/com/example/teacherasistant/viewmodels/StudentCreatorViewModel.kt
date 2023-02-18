package com.example.teacherasistant.viewmodels

import android.content.Context
import androidx.lifecycle.LiveData
import androidx.lifecycle.ViewModel
import androidx.lifecycle.asLiveData
import androidx.lifecycle.viewModelScope
import com.example.teacherasistant.database.AppDatabase
import com.example.teacherasistant.database.SubjectWithStudents
import com.example.teacherasistant.database.entities.Student
import com.example.teacherasistant.database.entities.SubjectStudentCrossRef
import com.example.teacherasistant.repositories.StudentRepository
import com.example.teacherasistant.repositories.SubjectStudentRepository
import kotlinx.coroutines.launch

class StudentCreatorViewModel(private val _context: Context, private val _subjectId: Long) :
    ViewModel() {
    private val _studentRepository =
        StudentRepository(AppDatabase.getInstance(_context).studentDao())
    private val _subjectStudentRepository =
        SubjectStudentRepository(AppDatabase.getInstance(_context).subjectDao(), _subjectId)

    private val _students: LiveData<List<Student>> = _studentRepository.students.asLiveData()
    val students: LiveData<List<Student>>
        get() = _students

    private val _subjectWithStudents: LiveData<SubjectWithStudents> =
        _subjectStudentRepository.subjectWithStudents.asLiveData()
    val subjectWithStudents: LiveData<SubjectWithStudents>
        get() = _subjectWithStudents

    suspend fun insertStudent(student: Student): Long = _studentRepository.insertStudent(student)

    fun insertSubjectWithStudent(subjectStudentCrossRef: SubjectStudentCrossRef) =
        viewModelScope.launch {
            _subjectStudentRepository.insertSubjectWithStudent(subjectStudentCrossRef)
        }
}