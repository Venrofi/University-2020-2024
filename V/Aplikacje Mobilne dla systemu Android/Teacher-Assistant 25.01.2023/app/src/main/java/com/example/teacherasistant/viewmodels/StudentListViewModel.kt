package com.example.teacherasistant.viewmodels

import android.content.Context
import androidx.lifecycle.LiveData
import androidx.lifecycle.ViewModel
import androidx.lifecycle.asLiveData
import androidx.lifecycle.viewModelScope
import com.example.teacherasistant.database.AppDatabase
import com.example.teacherasistant.database.SubjectWithStudents
import com.example.teacherasistant.repositories.SubjectStudentRepository
import kotlinx.coroutines.launch

class StudentListViewModel(private val _context: Context, private val _subjectId: Long) :
    ViewModel() {
    private val _subjectStudentRepository =
        SubjectStudentRepository(AppDatabase.getInstance(_context).subjectDao(), _subjectId)

    private val _subjectWithStudents: LiveData<SubjectWithStudents> =
        _subjectStudentRepository.subjectWithStudents.asLiveData()
    val subjectWithStudents: LiveData<SubjectWithStudents>
        get() = _subjectWithStudents

    fun deleteSubjectWithStudentByStudentId(subjectId: Long, studentId: Long) =
        viewModelScope.launch {
            _subjectStudentRepository.deleteSubjectWithStudentByStudentId(subjectId, studentId)
        }

    fun deleteSubjectStudentMarks(subjectId: Long, studentId: Long) = viewModelScope.launch {
        _subjectStudentRepository.deleteSubjectStudentMarks(subjectId, studentId)
    }
}