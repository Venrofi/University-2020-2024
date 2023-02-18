package com.example.teacherasistant

import android.content.Context
import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Button
import androidx.navigation.findNavController
import androidx.navigation.fragment.navArgs
import androidx.recyclerview.widget.RecyclerView
import com.example.teacherasistant.callback.FragmentCallback
import com.example.teacherasistant.viewmodels.StudentListViewModel

/**
 * A simple [Fragment] subclass.
 */
class StudentListFragment : Fragment() {
    private val _args: StudentListFragmentArgs by navArgs()

    private lateinit var _studentListViewModel: StudentListViewModel
    private lateinit var _studentListAdapter: StudentListAdapter

    private var callback: FragmentCallback? = null

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        // Inflate the layout for this fragment
        val view = inflater.inflate(R.layout.fragment_student_list, container, false)

        val subjectId: Long = _args.subjectId

        val studentListRecyclerView: RecyclerView =
            view.findViewById(R.id.student_list_recycler_view)

        _studentListViewModel = StudentListViewModel(activity as Context, subjectId)
        _studentListViewModel.subjectWithStudents.observe(viewLifecycleOwner) {
            _studentListAdapter = StudentListAdapter(it.students, _studentListViewModel, subjectId)
            studentListRecyclerView.adapter = _studentListAdapter
        }

        val addStudentButton: Button = view.findViewById(R.id.add_student_button)
        addStudentButton.setOnClickListener {
            val action =
                StudentListFragmentDirections.actionStudentListFragmentToStudentCreatorFragment(
                    subjectId
                )

            view.findNavController().navigate(action)
        }

        return view
    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
        if (callback != null) {
            changeText("Lista uczniów")
        }
    }

    override fun onAttach(context: Context) {
        super.onAttach(context)
        callback = context as FragmentCallback
    }

    override fun onDetach() {
        super.onDetach()
        callback = null
    }

    fun changeText(text: String) {
        callback?.onFragmentChanged(text)
    }
}